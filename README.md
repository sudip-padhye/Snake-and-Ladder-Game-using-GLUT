# Snake-and-Ladder-Game-using-GLUT
This game was designed using C and GLUT Library. It was my Undergrad College Project based on Computer Graphics Course. 
It involves 2 modes - 
1. Single Player (ie. Human Vs Computer) 
2. And, Two Player (Human Vs Human).

1. INTRODUCTION

1.1 Project Background
Snakes and Ladders (also known as Chutes and Ladders) is a classic children's game played on a square grid board. The objective is to be the first player to reach 100. Snakes or other perils can set you back, while ladders or other boons can help you advance quickly. It is played between two or more players on a gameboard having numbered, gridded squares.

1.2 Computer Graphics
Computer Graphics concerns the pictorial synthesis of real and imaginary objects from their computer based models. It provides one of the most natural means of communication with a computer and permits extensive, high bandwidth user computer interaction. Computer graphics is used today in many different areas like user interfaces. Plotting in business, science, office automation, electronic publishing and computer aided drafting and design, simulation and animation for scientific visualization and entertainment, cartography etc. 
Graphics are visual presentation on some surface, such as well, canvas, computer screen etc. Examples are photography, line art, graphs, engineering drawings, maps, typography etc. Graphics always combine text, illusion and colour. Graphics design may consist of the deliberation selection creation or arrangement of typography alone etc. Clarity or effective communication may be the objective, association with other cultural elements may be sought or merely the creation of a distinctive style.
1.3 Application of Computer Graphics
•	Display of information.
•	Design for animated games.
•	Simulation and animation.
•	User interface.
•	Display of information in Industries and Business.

	Display of information 
 Classical graphics techniques arose as a medium  to convey information among people. We have computer Potting Packages that provides a variety of plotting techniques and color tools that can handle multiple large sets.
	Design
Professional such as engineering and architecture are concerned with design. The use of interactive graphics tools in computer aided design pervades fields. Including as architecture, mechanical engineering, the design of very large scale integrated circuits and the creation of character for animations.

	Simulation and Animation
Once graphics systems evolved to be capable of generating sophisticated images in real time, engineers  and researches began to use them  simulators. One of the most  important uses has been in the training of pilots. Graphical flights simulation have proved to increase safety and to reduce training expenses.

	User interfaces
Interaction with computers has become dominated by a visual paradigm that includes windows, icons, menus and plotting device such s mouse. User interfaces demonstrate the variety of the available in high level modelling packages and the interactive devices the user can employ in modelling geometric objects.

1.4 Open GL
OpenGL is competing application programming interfaces (APIs).which can be used in applications to render 2D and 3D computer graphics, taking advantage of  hardware acceleration when available. Modern graphics processing unit (GPUs) may implement a particular version of the APIs .
OpenGL is a specification implemented in the C language, though it can use other programming languages. It is built on concept of a state machine, though more recent OpenGL  version  have transformed  it into much more object based system. As an API, OpenGL depends on no particular language feature, and can be made callable from almost any programming language with the proper bindings. Such bindings exist for Ada , BASIC (Blitz Max ( often used to Program Games ) , PureBasic, VisualBasic ), C#, Delphi, Fortran, Haskell, Java, Lisp, Lua, Pascal, Perl, Python, and Ruby. Graphics provide one of the most natural means of communicating with a computer, since our highly developed 2D and 3D pattern-recognition abilities allow us to perceive and process pictorial data rapidly and efficiently.

1.5 OpenGL Utility Tool Kit (GLUT)
As you know, OpenGL contains rendering commands but is designed to be independent of any window system or operating system. Consequently, it contains no commands for opening windows or reading events from the keyboard or mouse.
OpenGL drawing commands are limited to those that generate simple geometric primitive, GLUT includes several routines that creates more complicated three-dimensional objects such as a sphere, a torus and a teapot.
The OpenGL Utility Library, GLU also has quadrics routines that create some of the same three-dimensional objects as GLUT, such as a sphere, cylinder or cone.
The OpenGL Utility Toolkit (GLUT) is a programming interface with ANSIC and FORTAN bindings for writings window system independent OpenGL programs. The toolkit supports the following functionality:

•	Multiple windows for OpenGL rendering.
•	Call-back driven event processing.
•	Sophisticated input devices.
•	An "idle" routine and timers.
•	A simple, cascading pop-up menu facility.
•	Utility routines to generate various solid and wire frame objects.
•	Support for bitmap and stroke fonts.
•	Miscellaneous window management functions, including managing overlays.


2. PROJECT DEFINITION

"Snake & Ladder game"-
The game Snakes and Ladders has enthralled generations of children, and gone through a few name changes along the way. Sometimes sold as Chutes and Ladders in the United States, and originally Snakes and Ladders in India, the game has barely changed in all this time. 
Snakes and Ladders is a classic game of luck played on a 10x10 grid. The board features drawings of snakes and ladders connecting different squares together. If one should land at the base of a ladder, they advance to the top of the ladder. If the top of the snake is reached, the opposite effect occurs.

Players - Most Snakes and Ladders games require at least two people to take part.
Objective - The objective of most Snakes and Ladders games is to be the first player to get their game piece to the end of the board.

3.Inbuilt functions-
•	glBegin               //Delimits the vertices of a primitive or a group of like primitives
•	glEnd                //Delimits the vertices of a primitive or a group of like primitives
•	glClear             //clears buffers to assigned values
•	glClearColor    //specifies clear values for the background color
•	glFlush            //forces execution of openGL function quickly at once
•	glColor3f        //specifies RGB color values for primitives
•	glVertex2f      //specifies co-ordinates (x,y) values for the vertex position
•	glutDisplayFunc //specifies the function that is called whenever the contents of the window need to be redrawn
•	glutPostRedisplay //marks the current window as needing to be redrawn. At  the next oppurtunity, the callback function registered by glutDisplayFunc() will be called.
•	glutInitDisplayMode  //requests a display with the properties in arguments
•	glutMainLoop  //enters the GLUT processing loop, never to return.
•	glutCreateWindow  //creates new window for displaying the frame buffer contents
•	glutInitWindowSize  //specifies the initial height and width, in pixels of the window on the screen
•	glutInitWindowPosition //specifies the top-left corner of the window measured in pixels, from the top left corner of the screen

User defined functions-
•	void init(); //it is used to initialize the output window 
•	void start_screen(); //it is used to display the start screen
•	void print_text(int x,int y,char str[ ],float r,float g,float b); //used to display text
•	void frontscreen(); //used to display front screen
•	void load_screen(); // the Loading screen is displayed using this function
•	void display(); //it is the function used to display the output which is called to display certain changes
•	void locpt_conv(int loc); //converts the block no. into its corresponding bottom-left co-ordinates
•	void disp_fig(); //displays player's coins
•	void dice(); //used to display the no. of dots on dice based on random no. generated
•	void throw_dice(); //used to generate no. and change the player position
•	void menu(int id); //used for displaying right mouse button menu
•	void mouse(int btn,int state,int x,int y); //its a mouse driven function which detects any mouse interaction
•	void keys( unsigned char key, int x, int y ); //a keyboard driven function that detects keyboard    interaction
