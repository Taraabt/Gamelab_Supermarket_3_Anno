import unreal
import json
import os

audit_path = os.path.join(unreal.Paths.project_saved_dir(), 'AssetDependencyAudit.json')
with open(audit_path, 'r', encoding='utf-8') as handle:
    audit = json.load(handle)

roots = {
    '/Game/Project/Level/Main/Blockout_Magazzino_DEF',
    '/Game/Project/Level/Main/LV_MainMenu',
    '/Game/Project/Blueprint/Core/BP_DefaultGamemodeBase',
    '/Game/Project/Blueprint/Core/BP_GameInstance',
}
by_package = {row['package']: row for row in audit}
reachable = set()
pending = list(roots)
while pending:
    package = pending.pop()
    if package in reachable:
        continue
    reachable.add(package)
    pending.extend(by_package.get(package, {}).get('dependencies', []))

registry = unreal.AssetRegistryHelpers.get_asset_registry()
deleted = []
failed = []
for row in audit:
    package = row['package']
    if package in reachable:
        continue
    if unreal.EditorAssetLibrary.delete_asset(package):
        deleted.append(package)
    else:
        failed.append(package)

report_path = os.path.join(unreal.Paths.project_saved_dir(), 'DeletedUnreachableAssets.json')
with open(report_path, 'w', encoding='utf-8') as handle:
    json.dump({'deleted': deleted, 'failed': failed}, handle, indent=2)

unreal.log('Deleted {} unreachable assets; {} failed. Report: {}'.format(len(deleted), len(failed), report_path))
