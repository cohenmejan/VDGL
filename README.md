# VDGL
A Core OpenGL function loader.

Supports up to OpenGL 4.6

## Platforms

* Windows

# Installation

## Source

1. Clone the repository

	```git clone https://github.com/cohenmejan/VDGL.git```

2. Build project files
	
	Run GenerateVS2022Projects.bat

	OR

	Manually call a premake command from the root directory

	```Dependencies/premake/premake5.exe```

3. Compile the VDGL project

	Available configurations are Debug and Release

	Binaries will be output at

	```.../bin/(Configuration)/```

4. Link VDGL.lib from the output binaries to your project

5. Add the VDGL source folder as an include path in your project

	```.../VDGL/Source```

