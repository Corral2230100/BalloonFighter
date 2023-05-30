let project = new Project('Balloon Fighter');

project.addIncludeDir("TheEngine/Includes")
project.addFile('Balloon Fighter Game/**');
project.setDebugDir('Deployment');
project.flatten();

const otherproj = await project.addProject("TheEngine");
otherproj.addProvider(project,true);
resolve(project);
