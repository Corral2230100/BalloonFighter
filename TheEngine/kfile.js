const fs = require('fs');
let project = new Project('Engine');
fs.copyFileSync('./SDL2/lib/SDL2.dll','Deployment/SDL2.dll')
fs.copyFileSync('./SDL2/lib/SDL2_image.dll','./Deployment/SDL2_image.dll')
fs.copyFileSync('./SDL2/lib/SDL2_ttf.dll','./Deployment/SDL2_ttf.dll')
project.addProvider = function(proj,isGame = false)
{
    if(!isGame)
    {
        proj.addIncludeDir("C:/Program Files (x86)/Visual Leak Detector/include");
    }
    proj.addIncludeDir("./SDL2/include");
    proj.addLib("./SDL2/lib/SDL2");
    proj.addLib("./SDL2/lib/SDL2main");
    proj.addLib("./SDL2/lib/SDL2_image");
    proj.addLib("./SDL2/lib/SDL2_ttf");
    proj.addLib("C:/Program Files (x86)/Visual Leak Detector/lib/Win64/vld");
}

project.addIncludeDir("TheEngine/Includes");
project.addFiles('Sources/**',"Includes/**");
project.addDefine("KINC_STATIC_COMPILE");
project.isStaticLib = true;
project.addProvider(project,false);

resolve(project);
