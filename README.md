Code Standards
=============
- All Singletons are named Managers. Example: GameManager

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