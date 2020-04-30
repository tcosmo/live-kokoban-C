# Live Coding: KOKOBAN in C!!!

Kokoban is our live-coding implementation of the [Sokoban Game](https://fr.wikipedia.org/wiki/Sokoban).      

Find the live coding youtube video [HERE](https://www.youtube.com/channel/UCGhXJzpdUSGKZ_cHBZtdLjg)!!!

# Getting Started

If you are up for the challenge and want to code Kokoban yourself from scratch, just checkout this [Initial Commit](https://github.com/tcosmo/live-kokoban-C/tree/) of the repo!! Install the Allegro 5 dependency on your system (see below).     

In practice:
- `git clone https://github.com/tcosmo/live-kokoban-C.git`
- `cd live-kokoban-C`      
- `git checkout `
- Run `make` in order to compile 
- Run `./build/kokoban.out` (or `.\build\kokoban.out` on windows)

You're ready to get going :))

# Acknowledgement

We took the `levels/default.txt` levels file from `davidjoffe` repository: [https://github.com/davidjoffe/sokoban](https://github.com/davidjoffe/sokoban). 

The tiles of the games were found on [https://opengameart.org/](https://opengameart.org/) under [CC0 License](https://creativecommons.org/publicdomain/zero/1.0/) (public domain), credits go to [Kenney](www.kenney.nl).

# Dependencies

## Allegro 5
We use [Allegro 5](https://github.com/liballeg/allegro5) as the graphic library for the project. That's the only dependency.

Here's how to install it (extracted from there [Tutorial](https://github.com/liballeg/allegro_wiki/wiki/Quickstart)).

### Choose your OS

<details>
<summary>Linux</summary>

#### Ubuntu 18.04+ (or derivatives thereof)

First, add the Allegro PPA. This gives you up-to-date versions of Allegro; the base repos only provide 5.2.3 at the time of writing.

```bash
sudo add-apt-repository ppa:allegro/5.2
```

Then, install Allegro:

```bash
sudo apt install liballegro*5.2 liballegro*5-dev
```

#### Fedora

```bash
sudo dnf install allegro5*
```

#### Others

Binary packages may be available for your distro; feel free to add them here if so.

Otherwise, select "Something else" below.

</details>

<details>
<summary>OSX</summary>

#### Install with [Homebrew](https://brew.sh/)

```bash
brew install allegro
```

</details>

<details>
<summary>Windows</summary>

#### Visual Studio 2015+

Install per-project using [NuGet](https://www.nuget.org/) in PowerShell:

```ps1
cd MyProjectDir\
Install-Package Allegro
```

Or, just [[install from within Visual Studio|Allegro in Visual Studio#using-nuget-within-visual-studio]].

#### MinGW

* Download [Allegro 5.2.4 for MinGW](https://github.com/liballeg/allegro5/releases/download/5.2.4.0/allegro-x86_64-w64-mingw32-gcc-7.2.0-posix-seh-dynamic-5.2.4.1.zip).
  * Note that Allegro 5.2.4 is the latest release at the time of writing; make sure you check the [releases page](https://github.com/liballeg/allegro5/releases).
* Extract the relevant directories into your MinGW install's include & library paths:
  * Find out where you installed MinGW (`C:\MinGW` is the default).
  * The .zip contains three directories under `allegro\`: `bin\ include\ lib\`.
  * Extract the files from each to eg. `C:\MinGW\bin`, `C:\MinGW\include`, `C:\MinGW\lib` respectively.

</details>

<details>
<summary>Android</summary>

<br>Using Allegro for mobile apps is a bit trickier. We recommend building a desktop program first.

See the [Maven repository](https://github.com/liballeg/android).

</details>

<details>
<summary>iOS</summary>

<br>Using Allegro for mobile apps is a bit trickier. We recommend building a desktop program first.

See the [iOS README](https://github.com/liballeg/allegro5/blob/master/README_iphone.txt).

**TODO:** [Adapt from this.](https://wiki.allegro.cc/index.php?title=IOS_and_Allegro_5)

</details>

<details>
<summary>Something else</summary>

#### Install from source

If you're running another OS or want to do something that's not possible with the provided binary packages (eg. static linking often isn't trivial with them), you'll need to [[build Allegro from source|Installation in depth#installing-from-sources]].

</details>
