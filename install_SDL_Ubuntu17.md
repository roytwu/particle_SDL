Installing SDL2.0 (Simple DirectMedia Layer) on Ubuntu17.1 64 bit: 


1.Go to the official website of SDL (https://www.libsdl.org/download-2.0.php), download the latest source code ("SDL2-2.0.8.tar.gz -GPG signed", 06/03/2018)  


2. Before installing SDL, install dependecy packages first: 
```shell
	sudo apt install libesd0-dev              (for SDL2)
	sudo apt install libwebp-dev libtiff-dev  (for SDL2_image)
```

3. Extract the source code file  


4. cd into the directory created and start SDL installation by runing the following commands: 
```shell
	./configure
	make
	sudo make install
	sudo ldconfig
```

5. In the makefile:
	adding header file path: CFLAGS += -I /usr/local/include/SDL2
	addubg library:          LDFLAGS += -lSDL2    	

Other resources:   
	http://forum.outpost2.net/index.php?topic=5978.0  
	https://askubuntu.com/questions/344512/what-is-the-general-procedure-to-install-development-libraries-in-ubuntu  


*** Update 06/05/2018 ***   
SDL_Init(SDL_INIT_VIDEO) failed,    
SDL_GetError() provides error message: "No available video device"     

In the command line, run:
```shell
	sudo apt install xorg-dev
```

Repeat Step 4. SDL Init succeeded!	





