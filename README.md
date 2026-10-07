# GoldenEye 007: PS Vita Port

![license](https://img.shields.io/badge/license-MIT-green)
![platform](https://img.shields.io/badge/platform-PS%20Vita-blue)

A native PS Vita port of _GoldenEye 007_ (Rare, 1997, Nintendo 64). This is
built on top of the [GoldenEye 007 PC port](https://github.com/jkdansereau/goldeneye-pc-port),
which compiles the original N64 game from the
[GoldenEye 007 decompilation](https://github.com/n64decomp/007), retargeted
for Vita hardware. It runs the original N64 game from its reconstructed
source code.

The full single-player campaign has been played start to finish on a Vita,
end credits included. Known issues are listed under [Status](#status). Free
to download, build on and modify (you bring the ROM).

> [!IMPORTANT]
> **You must supply your own GoldenEye 007 ROM.** This repository contains no
> Nintendo code or assets, and no ROM. Nothing here is distributable as a
> playable game: see [Requirements](#requirements) and [Legal](#legal).

## Download

| Platform | Bundle | Notes |
|---|---|---|
| **PS Vita / PS TV** | [GE007Vita.vpk](https://github.com/kaziema/goldeneye-pc-port/releases) | The app. Your ROM goes next to it on the memory card. |

The VPK contains **no ROM and no game assets**: you supply your own (see
[Requirements](#requirements)). You can also build it yourself; see
[Building](#building).

### Installation

You'll need a Vita that's already homebrew-enabled (h-encore/HENkaku) with
VitaShell installed. That part isn't covered here.

1. On your Vita, open VitaShell and go to `ux0:/data/`.
2. Press **Triangle**, choose **New**, and name the new folder `GoldenEye007`. You should now have `ux0:data/GoldenEye007`.
3. Get two files into that `GoldenEye007` folder (FTP or USB transfer with VitaShell, whichever you normally use):
   - `GE007Vita.vpk`
   - Your own **US** ROM in big-endian `.z64` format, named exactly `ge007.ntsc-final.z64` or `baserom.u.z64`. Your own dump, not a downloaded one.
4. In VitaShell, go into `ux0:data/GoldenEye007`, highlight `GE007Vita.vpk`, and press **X**. Press **X** again to accept the extended-permissions prompt. That installs the app. The `.vpk` can stay in the folder or be deleted afterward.
5. Launch GoldenEye 007 from the LiveArea like any other app.

The first launch takes a while. The game reads your ROM and converts the
level, model and texture data it needs, then saves the result to the memory
card so it only happens once. It also creates `log.txt` and a `shadercache`
folder in `ux0:data/GoldenEye007` on its own. You don't need to make those.

### Updating

Drop the new `GE007Vita.vpk` into `ux0:data/GoldenEye007`, highlight it in
VitaShell, and press **X** twice like the first install. Every build uses the
same Title ID (`GEVT00001`), so it installs over the old version in place.

Some updates change how assets are converted. When that happens the game
redoes the first-launch conversion on its own, so the first boot after that
update takes longer again.

Your save is safe either way. It lives at `ux0:data/GoldenEye007/ge007.eep`
and isn't part of the app package, so installing an update or deleting the
app doesn't touch it.

## Status

**Playable.** All 20 solo missions and the ending
credits have been played through on Vita hardware by testers. Feedback and
logs are very welcome.

**Working:** boot sequence and front end; all 20 solo missions load and run;
end credits; full audio (music and sound effects); Vita controls with
dedicated Action and Reload buttons and D-pad stance and strafe; the watch
menu options; the in-game options overlay on **Select**; saves to the
memory card; compiled shaders are cached to `ux0:data/GoldenEye007/shadercache`,
so the hitch the first time a new effect appears only happens once.

Done so far on the Vita side:

- `Makefile.vita` wired end to end, producing a working VPK with LiveArea art
- Asset conversion moved onto the Vita itself, so no PC tools or Python are needed to play
- Fixed the shader compiler hang on Vita's runtime GLSL compiler, and shaders are trimmed down to what each one uses
- Fixed enemies spawning sunk into the floor (a 64-bit struct layout that the PC port depends on)
- Fixed a crash from an animation table that ran past its end
- Fixed Bond's position going invalid on Facility and Bunker
- Fixed the crash during the end credits
- Fixed a sound system hang caused by the Vita's multiple CPU cores racing on the audio list
- Fixed the watchdog falsely flagging the game as frozen
- Fixed missing textures on the Nintendo and Rareware logos and the menu folders
- Fixed textures that wrap at the edge of the texture memory
- Fixed door textures swapping to the wrong image
- More sound effect slots, so heavy scenes (the tank) don't cut sounds
- Frame pacing locked to the Vita's display refresh
- Rooms past the fog distance are skipped instead of drawn
- Lighter explosions and smoke to keep the frame rate up in big fights
- Vita-friendly default settings on first launch (draw distance, FOV, MSAA, filtering)
- Fullscreen and Resolution options hidden, since the Vita screen is fixed at 960x544
- Options menu renamed to Vita Options
- Logs open with a build stamp, and crashes write `ge007.crash.log`

**Known issues:**

- Runs at 60 fps. Busy scenes and big open levels can drop to around 40 fps.
- Glass on Facility is missing its reflection.
- With **Native widescreen** on, the picture shows black bars on the sides.
- The **Control Style** watch option is locked to one layout for now, since the Vita button layout is set in the port.
- The first time a new effect or area appears there can be a short hitch while its shader compiles. After that it's cached.
- Issues listed in the [PC port's README](https://github.com/jkdansereau/goldeneye-pc-port#status) that aren't Vita-specific (muzzle flash streaks, water seams, Surface 1 trees, and so on) apply here too.

## Roadmap

No fixed timeline, but here's what's next:

- A steady 60 fps. Most of the remaining cost is on the CPU side of the renderer.
- Fixing the known issues above.
- Pulling in fixes from the upstream PC port as they land.
- PAL and JP ROM support, following the PC port.

## Beyond playing

- **Tweak it**: `ux0:data/GoldenEye007/ge007.ini` and the Vita Options
  overlay (press **Select**) cover frame cap, MSAA, texture filtering, FOV
  and draw distance.
- **Read it**: [`docs/internals.md`](docs/internals.md) maps the
  architecture and the software RSP; [`docs/porting-notes.md`](docs/porting-notes.md)
  covers the N64 to PC bug classes. Most of what applies to PC applies here,
  plus 32-bit and multicore problems the Vita adds on top.
- **Mod it**: the port layer and `Makefile.vita` are yours to extend
  (see [License](#license)).
- **Report it**: if something breaks, send `ux0:data/GoldenEye007/log.txt`
  (and `ge007.crash.log` if there is one) along with what you were doing.

## How this differs from the PC port

Both ports share the same game code. The differences:

| | PC port | This port |
|---|---|---|
| **Hardware** | x86_64 desktop, Steam Deck | PS Vita / PS TV (32-bit ARM, 4 cores) |
| **Graphics** | OpenGL through glad | [vitaGL](https://github.com/Rinnegatamante/vitaGL) with the Vita's runtime shader compiler |
| **Asset conversion** | Python sidecar converters on your PC | Converted on the Vita on first launch |
| **Display** | Any resolution, windowed or fullscreen | Fixed 960x544 |
| **Controls** | Keyboard, mouse, or controller | Vita buttons, layout set by the port |
| **Build** | CMake | `Makefile.vita` with VitaSDK |

## Requirements

You need a GoldenEye 007 (Nintendo 64) ROM that you legally own, in
big-endian (`.z64`) format:

| Region | ROM filename (in `ux0:data/GoldenEye007/`) | SHA-1 |
|--------|---------------------------|-------|
| NTSC-U (US) | `ge007.ntsc-final.z64` or `baserom.u.z64` | `abe01e4aeb033b6c0836819f549c791b26cfde83` |

Only the US version is supported. PAL and JP are not yet.

You also need a homebrew-enabled PS Vita or PS TV.

## Building

Prerequisites:

- [VitaSDK](https://vitasdk.org/)
- vitaGL, vitaShaRK, math-neon, SDL2 and zlib (available through `vdpm`)

```sh
git clone https://github.com/kaziema/goldeneye-pc-port.git
cd goldeneye-pc-port
git checkout vita
export VITASDK=$HOME/vitasdk
export PATH=$VITASDK/bin:$PATH
make -f Makefile.vita all -j8
```

Produces `GE007Vita.vpk` in the repo root. The build doesn't need your ROM;
the game reads it on the Vita at first launch.

## Running

Install the VPK as described in [Installation](#installation) and launch it
from the LiveArea. Everything the game writes lives in
`ux0:data/GoldenEye007/`:

| File | What it is |
|---|---|
| `ge007.eep` | Your save |
| `ge007.ini` | Settings, written on first run |
| `log.txt` | Log for the current session |
| `ge007.crash.log` | Written if the game crashes |
| `shadercache/` | Compiled shaders |

### Default controls

| Action | In game | In menus |
|---|---|---|
| Move | Left stick | Navigate |
| Look | Right stick | |
| Fire | R | |
| Aim | L | |
| Action (doors, switches, get in/out of tank) | Cross | Accept |
| Reload | Square | |
| Next weapon | Triangle | |
| Previous weapon | Circle | Back |
| Crouch | D-pad down | Navigate |
| Stand up | D-pad up | Navigate |
| Strafe left | D-pad left | Navigate |
| Strafe right | D-pad right | Navigate |
| Pause | Start | |
| Vita Options | Select | |

## How it works

The game code in `src/` is the decompilation, compiled as written. Everything
that would touch N64 hardware goes through `port/`, inherited from the PC
port: a **software RSP** (`port/fast3d/`) that reads the display lists the
game builds each frame and turns them into OpenGL draws, plus shims for the
N64 OS, video, audio, input, timers and save storage.

On top of that, the Vita side:

- swaps the OpenGL backend onto vitaGL and compiles shaders with the Vita's
  runtime compiler, caching them on the memory card;
- runs the asset conversion on the device in C (`port/src/pcconv_*.c`),
  mirroring the PC port's Python converters;
- keeps the original N64 struct layouts where the PC port widened them for
  64-bit, since the Vita is 32-bit like the N64;
- adds locking where the N64 relied on having a single CPU core;
- drives the game's frame timing from the Vita's display refresh.

```
Makefile.vita       Vita build (VPK + LiveArea packaging)
livearea/           LiveArea art and layout
CMakeLists.txt      PC build
src/  include/      the decompilation (game + libultra)
port/
  fast3d/           software RSP -> OpenGL / vitaGL
  src/              port layer (main, OS shims, video, audio, input, fs,
                    on-device asset conversion, ...)
  include/          port-facing headers
tools/  Makefile    the N64 build (from the decomp)
tools_pc/           PC-port helper and analysis scripts
docs/               see below
```

## Documentation

| Doc | What's in it |
|---|---|
| [`docs/internals.md`](docs/internals.md) | Architecture and the RSP approach, from the PC port. |
| [`docs/porting-notes.md`](docs/porting-notes.md) | The recurring N64 to PC bug classes, with fixes. |
| [`docs/building.md`](docs/building.md) | The PC build and asset-extraction guide. |
| [`docs/dev/`](docs/dev/) | The PC port's engineering record: finding log, per-level status, graphics backlog. |

## Credits

This project stands entirely on other people's shoulders:

- **[jkdansereau](https://github.com/jkdansereau)** built the
  [GoldenEye 007 PC port](https://github.com/jkdansereau/goldeneye-pc-port),
  which this is built from. The port layer, the software RSP integration, the
  asset converters and the long list of N64 to PC fixes are theirs.
- The [GoldenEye 007 decompilation](https://github.com/n64decomp/007), years
  of work by Larry Ficken ("kholdfuzion") and the project's contributors, plus
  zoinkity's GoldenEye documentation that the decomp started from.
- The [Perfect Dark PC port](https://github.com/fgsfdsfgs/perfect_dark)
  (Ryan Dwyer and contributors), the reference architecture for the PC port
  and the source of the `fast3d` software RSP.
- **[Rinnegatamante](https://github.com/Rinnegatamante)** for vitaGL,
  vitaShaRK and the Vita ports whose patterns this platform layer follows.
- The [VitaSDK](https://vitasdk.org/) team.

**Vita port**

- **[kaziema](https://github.com/kaziema)**: PS Vita port
- **vizer**, **midnightneon** (mano), **mikey**, **saturn** and **ben**: testing, logs, and full campaign runs

If you're one of these people reading this, thank you!

## Legal

This is a non-commercial fan preservation project, in the same category as the
many other N64 decompilation and native-port repositories on GitHub:

- **No ROM and no game assets are distributed**: not in this repository and
  not in any release. Textures, audio, models, level data and in-game text are
  read from a ROM *you already own*, on *your* Vita.
- The repository is a fork of the
  [GoldenEye 007 PC port](https://github.com/jkdansereau/goldeneye-pc-port),
  itself a fork of the public
  [GoldenEye 007 decompilation](https://github.com/n64decomp/007) (see
  [`NOTICE`](NOTICE) for what that includes).
- No official logos, box art, or marketing assets are used. "GoldenEye 007",
  "007", "James Bond" and related marks belong to their respective owners
  (Nintendo, Microsoft/Rare, MGM, Danjaq, EON Productions).
- I don't condone piracy. Bring your own legally obtained copy.

This project is **not affiliated with, endorsed by, or sponsored by** Nintendo,
Rare, Microsoft, MGM, Danjaq, EON Productions, Sony, or any rights holder in
GoldenEye or James Bond. If you are a rights holder with a concern, open an
issue and it will be addressed.

## License

The original work in this repository (the port layer in `port/`, the build
systems, `tools_pc/`, and the documentation) is released under the MIT
License; see [`LICENSE`](LICENSE). Everything inherited from the upstream
decompilation is covered by [`NOTICE`](NOTICE), not by that license.
