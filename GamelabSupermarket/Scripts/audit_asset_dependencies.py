import unreal
import json
import os

registry = unreal.AssetRegistryHelpers.get_asset_registry()
assets = registry.get_assets_by_path(unreal.Name('/Game'), recursive=True, include_only_on_disk_assets=True)

def text_name(value):
    return str(value)

rows = []
for asset in assets:
    package = text_name(asset.package_name)
    dependencies = registry.get_dependencies(asset.package_name, unreal.AssetRegistryDependencyOptions(
        include_hard_package_references=True,
        include_soft_package_references=True,
        include_searchable_names=False,
        include_soft_management_references=True,
        include_hard_management_references=True,
    ))
    referencers = registry.get_referencers(asset.package_name, unreal.AssetRegistryDependencyOptions(
        include_hard_package_references=True,
        include_soft_package_references=True,
        include_searchable_names=False,
        include_soft_management_references=True,
        include_hard_management_references=True,
    ))
    rows.append({
        'package': package,
        'asset': text_name(asset.asset_name),
        'class': text_name(asset.asset_class_path.asset_name),
        'file': text_name(asset.package_path),
        'dependencies': sorted(text_name(x) for x in dependencies if text_name(x).startswith('/Game/')),
        'referencers': sorted(text_name(x) for x in referencers if text_name(x).startswith('/Game/')),
        'parent_class': text_name(asset.get_tag_value('ParentClass') or ''),
        'native_parent_class': text_name(asset.get_tag_value('NativeParentClass') or ''),
    })

target = os.path.join(unreal.Paths.project_saved_dir(), 'AssetDependencyAudit.json')
with open(target, 'w', encoding='utf-8') as handle:
    json.dump(rows, handle, indent=2)
unreal.log('Wrote asset audit: {}'.format(target))
