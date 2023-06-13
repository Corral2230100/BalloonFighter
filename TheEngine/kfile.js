const fs = require('fs');
let project = new Project('Engine');
fs.copyFileSync('./SDL2/lib/SDL2.dll','Deployment/SDL2.dll')
fs.copyFileSync('./SDL2/lib/SDL2_image.dll','./Deployment/SDL2_image.dll')
fs.copyFileSync('./SDL2/lib/SDL2_ttf.dll','./Deployment/SDL2_ttf.dll')
fs.copyFileSync('./SDL2/lib/SDL2_mixer.dll','./Deployment/SDL2_mixer.dll')
project.addProvider = function(proj,isGame = false)
{

    proj.addIncludeDir("C:\\Program Files (x86)\\Visual Leak Detector\\include");
    
    
    proj.addLib("./SDL2/lib/SDL2");
    proj.addLib("./SDL2/lib/SDL2main");
    proj.addLib("./SDL2/lib/SDL2_image");
    proj.addLib("./SDL2/lib/SDL2_ttf");
    proj.addLib("./SDL2/lib/SDL2_mixer");
    proj.addLib("C:/Program Files (x86)/Visual Leak Detector/lib/Win64/vld");
}
project.addIncludeDir("./SDL2/include");
project.addIncludeDir("TheEngine/Includes");
project.addIncludeDir("C:\\Program Files (x86)\\Visual Leak Detector\\include");
project.addFiles('Sources/**',"Includes/**");
project.addFile("./SDL2/include/SDL_ttf.h");
project.addDefine("KINC_STATIC_COMPILE");
project.isStaticLib = true;
project.addProvider(project,false);

resolve(project);
