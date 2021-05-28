# mesh-viewer

OPenGL applications for viewing meshes

## How to build

*Windows*

Open git bash to the directory containing this repository.

```
mesh-viewer $ mkdir build
mesh-viewer $ cd build
mesh-viewer/build $ cmake -G "Visual Studio 16 2019" ..
mesh-viewer/build $ start CS312-MeshViewer.sln
```

Your solution file should contain multiple projects, such as `mesh-viewer`.
To run from the git bash command shell, 

```
mesh-viewer/build $ ../bin/Debug/mesh-viewer
```

*macOS*

Open terminal to the directory containing this repository.

```
mesh-viewer $ mkdir build
mesh-viewer $ cd build
mesh-viewer/build $ cmake ..
mesh-viewer/build $ make
```

To run each program from build, you would type

```
mesh-viewer/build $ ../bin/mesh-viewer
```

## Simple Mesh
<img src='./gifs/simple.gif'  width='550' />

## Unlit Shading
<img src='./gifs/billboard.gif'  width='550' />

## Phone Shading
I am not sure why the mesh is not showing the correct result. I think there is something wrong in phone.vs, but I wasn't able to find out the error. 

<img src='./gifs/mesh.gif'  width='550' />

