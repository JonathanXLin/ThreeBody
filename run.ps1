Remove-Item ThreeBody.exe

gcc `
src/engine/engine.c `
src/engine/state/state.c `
src/utils/utils.c `
src/window/window.c `
src/main.c `
-o ThreeBody.exe -O1 -Wall -std=c99 -Wno-missing-braces -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm

.\ThreeBody.exe