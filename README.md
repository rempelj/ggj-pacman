Code Standards
=============
- All Singletons are "Managers". Example: GameManager

GameObjects
==========
- Every entity in the game is represented as a GameObject.
- GameObjects can contain many GameComponents
- Each GameComponent provides a specific functionality 
- Every GameObject contains a Transform component to represent the object's position and size

Setup with OSX and Eclipse
=====================
- Install Allegro5: https://wiki.allegro.cc/index.php?title=Install_Allegro5_From_Git
- In Eclipse, Project Properties, C/C++ Build, Settings, GCC C++ Compiler, Includes: add `/usr/local/include` to Include paths (-I)
- Under MaxOS X C++ Linker, Libraries: Add `allegro` and `allegro_main` to Libraries (-l). Add `/usr/local/lib` to Library search path (-L).
- Make sure "Shared (-dynamiclib)" is **unchecked** under Shared Library Settings

Notes
=====
- This blog post was useful: http://partitionseven.blogspot.ca/2011/01/compiling-allegro-5-with-mac-os-x-snow.html
- This comment was useful: http://partitionseven.blogspot.ca/2011/01/compiling-allegro-5-with-mac-os-x-snow.html?showComment=1305307581354#c606053369828396569