#include "plugin.h"
#include "iCubCam.h"
#include <cedar/processing/ElementDeclaration.h>

void pluginDeclaration(cedar::aux::PluginDeclarationListPtr plugin)
{
    cedar::proc::ElementDeclarationPtr summation_decl
    (
        new cedar::proc::ElementDeclarationTemplate <iCubCam>("Utilities")
    );
    plugin->add(summation_decl);
}
