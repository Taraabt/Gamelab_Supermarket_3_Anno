import unreal
import json
import os

registry = unreal.AssetRegistryHelpers.get_asset_registry()
redirectors = [
    asset for asset in registry.get_assets_by_path(unreal.Name('/Game'), recursive=True, include_only_on_disk_assets=True)
    if str(asset.asset_class_path.asset_name) == 'ObjectRedirector'
]

result = {'found': len(redirectors), 'packages': [str(asset.package_name) for asset in redirectors]}
if redirectors:
    unreal.AssetToolsHelpers.get_asset_tools().fixup_referencers(redirectors, False, True)

remaining = [
    asset for asset in registry.get_assets_by_path(unreal.Name('/Game'), recursive=True, include_only_on_disk_assets=True)
    if str(asset.asset_class_path.asset_name) == 'ObjectRedirector'
]
result['remaining'] = len(remaining)
report_path = os.path.join(unreal.Paths.project_saved_dir(), 'RedirectorCleanupReport.json')
with open(report_path, 'w', encoding='utf-8') as handle:
    json.dump(result, handle, indent=2)
unreal.log('Fixed {} redirectors; {} remain.'.format(result['found'], result['remaining']))
