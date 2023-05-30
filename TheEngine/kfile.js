const fs = require('fs');
let project = new Project('Engine');
fs.copyFileSync('./SDL2/lib/SDL2.dll','Deployment/SDL2.dll')
project.addProvider = function(proj,isGame = false)
{
    if(!isGame)
    {
        proj.addIncludeDir("./SDL2/include");
    }
    proj.addLib("./SDL2/lib/SDL2");
    proj.addLib("./SDL2/lib/SDL2main");
}

project.addIncludeDir("TheEngine/Includes");
project.addFiles('Sources/**',"Includes/**");
project.addDefine("KINC_STATIC_COMPILE");
project.isStaticLib = true;
project.addProvider(project,false);

resolve(project);
