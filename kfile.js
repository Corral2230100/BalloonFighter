let project = new Project('Balloon Fighter');

project.addIncludeDir("TheEngine/Includes")
project.addIncludeDir("./SDL2/include");
project.addIncludeDir("Balloon Fighter Game/Includes")
project.addFile('Balloon Fighter Game/**');
project.setDebugDir('Deployment');
project.flatten();

const otherproj = await project.addProject("TheEngine");
otherproj.addProvider(project,true);
resolve(project);
