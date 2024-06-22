# Takes XML `.props` file with list of sources and creates XML `.filters` file
# with `<Filter>` item groups reflecting the directory structure of the sources.
#
# Usage:
#   python filters_from_sources.py <input.props> <output.filters>

import sys
import os
import xml.etree.ElementTree as ET
import uuid


# WTF!? Why isn't there a built-in function for this?
def strip_xml_ns(tag_name):
    splits = tag_name.split('}')

    if len(splits) == 1:
        return splits[0]
    
    return splits[1]


def main():
    if len(sys.argv) != 3:
        print("Usage: python filters_from_sources.py <input.props> <output.filters>")
        sys.exit(1)

    input_file = sys.argv[1]
    output_file = sys.argv[2]

    tree = ET.parse(input_file)
    root = tree.getroot()

    # Traverse root and look for `ItemGroup` elements with `ClCompile` and `ClInclude` children
    # and create a dictionary with source file paths as keys
    sources = {}
    for item_group in root:
        if strip_xml_ns(item_group.tag) != 'ItemGroup':
            continue
        
        for item in item_group:
            tag_name = strip_xml_ns(item.tag)

            if tag_name == 'ClCompile' or tag_name == 'ClInclude':
                sources[item.attrib['Include']] = None
    
    # Find longest common prefix of all source file paths
    common_prefix = os.path.commonprefix(list(sources.keys()))
    print('Common prefix:', common_prefix)

    # Create a dictionary with all possible subdirectory paths, for example:
    #   fheroes2
    #   fheroes2\agg
    #   fheroes2\ai
    #   fheroes2\ai\combat
    #   ...etc.
    subdirs = {}

    for source in sources:
        source = source[len(common_prefix):]
        source = source.split(os.sep)

        for i in range(1, len(source)):
            subdir = os.sep.join(source[:i])
            subdirs[subdir] = None

    subdirs = sorted(subdirs.keys())

    # Create new `ItemGroup` under the root element and add `Filter` elements
    # for each subdirectory.
    # 
    # The filter element should look like this:
    #  <Filter Include="fheroes2">
    #    <UniqueIdentifier>{85ced9d1-01c0-4ab2-b938-effb45a4bb8e}</UniqueIdentifier>
    #  </Filter>
    root.append(ET.Element('ItemGroup'))
    item_group = root[-1]

    for subdir in subdirs:
        filter = ET.Element('Filter')
        filter.attrib['Include'] = subdir
        item_group.append(filter)

        # Add `UniqueIdentifier` element with a random UUID
        unique_identifier = ET.Element('UniqueIdentifier')
        unique_identifier.text = '{' + str(uuid.uuid4()) + '}'

        filter.append(unique_identifier)

    # Go through all `ClCompile` and `ClInclude` again and add `Filter` elements with
    # the corresponding subdirectory paths
    for item_group in root:
        if strip_xml_ns(item_group.tag) != 'ItemGroup':
            continue
        
        for item in item_group:
            tag_name = strip_xml_ns(item.tag)

            if tag_name == 'ClCompile' or tag_name == 'ClInclude':
                filter_subdir = item.attrib['Include']
                filter_subdir = filter_subdir[len(common_prefix):]
                filter_subdir = filter_subdir[:filter_subdir.rfind(os.sep)]

                filter = ET.Element('Filter')
                filter.text = filter_subdir
                item.append(filter)

    # Write the new XML tree to the output file, formatted
    ET.indent(tree.getroot())
    ET.register_namespace("", "http://schemas.microsoft.com/developer/msbuild/2003")
    tree.write(output_file, encoding='utf-8', xml_declaration=True, method='xml')


if __name__ == '__main__':
    main()
