# CC-14-Computer-Graphics-Lab

This is the repository for Dhruba Saha's Computer Graphics Lab assignments for CC-14. It contains code and other resources related to OpenGL programming in C.

## Step 1: Update and Upgrade Your System

First, ensure your system is up to date:

```sh
sudo apt update
sudo apt upgrade -y
```

## Step 2: Install Essential Build Tools

Install the essential build tools required for compiling C programs:

```sh
sudo apt install build-essential
```

## Step 3: Install OpenGL Development Libraries

Install the FreeGLUT development libraries necessary for OpenGL development:

```sh
sudo apt-get install freeglut3-dev
```

## Step 4: Clone the Repository

Clone the repository containing the OpenGL C programs:

```sh
git clone https://github.com/dhrubasaha08/CC-14-Computer-Graphics.git
```

## Step 5: Navigate to the Practical Directory

Change to the directory containing the practical examples:

```sh
cd CC-14-Computer-Graphics/practicals/
```

## Step 6: Compile an Example Program

Compile one of the example programs. For instance, to compile `DDA.c`, use the following command:

```sh
gcc DDA.c -lGL -lGLU -lglut -lm
```

## Step 7: Run the Compiled Program

Run the compiled program:

```sh
./a.out
```
