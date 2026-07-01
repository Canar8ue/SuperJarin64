# SuperJarin64 - Progress Track

## 📝 Simple Changelog
* **v1.3.1 (Warp Position Adjusted & Hitbox Increased):**
  * Adjusted middle window warp position (`Z=-2680`, `Y=850`) and increased detection radius to `200` (`BPARAM1(20)`) to account for solid wall collision.
  * Renamed `progress.me` to `progress.md`.
* **v1.3.0 (Warp Linked & Cleanup):**
  * Linked the Peach Room's middle window to the custom Tower of the Wing Cap sky course using exact player-verified coordinates (`X=1874`, `Y=768`, `Z=-2014`).
  * Removed the temporary debug coordinate display overlay.
* **v1.2.0 (Custom Level & Build Fixes):**
  * Implemented a massive custom sky obstacle course in the Tower of the Wing Cap (`levels/totwc/`).
  * Replaced warp pipes with a horizontal moving bridge to resolve build conflicts.
* **v1.1.0 (Debug Overlay & Window Prep):**
  * Added a temporary on-screen X, Y, Z coordinate HUD overlay for window warp alignment.
* **v1.0.0 (Modern Free Camera & CI):**
  * Added 360-degree free camera horizontal rotation with auto-alignment bypass while rotating.
  * Added L-button camera re-centering.
  * Setup automated GitHub Actions ROM compilation pipeline.

---

## 🚀 Project Overview

The goal of this project is to create a modern, more playable version of Super Mario 64. 

### Current Custom Features:
* **Smooth Camera Rotation:** Replaced the rigid 45/90/120 degree snap-locking camera angles with continuous, smooth horizontal rotation. Simply hold down **C-Left** or **C-Right** to pan around Mario.
* **Auto-Alignment Bypassed During Input:** Bypassed the auto-centering only while holding C-buttons, allowing you to choose and hold any angle. Once you release the buttons, the camera slowly centers behind Mario when running, just like the original game.
* **No Angle Restrictions:** Removed the 120-degree limit on camera angles, enabling full 360-degree orbital rotation around Mario.
* **L-Button Re-centering:** Press the **L Button** to instantly snap the camera directly behind Mario.
* **Automated Builds:** Built-in GitHub Actions pipeline to automatically compile and package the custom `.z64` ROM.

---

## 📁 Repository File Tree

Below is the directory structure of the repository, including descriptions of key folders and build files:

```text
SuperJarin64/
├── .github/
│   └── workflows/
│       └── build.yml             # GitHub Actions compilation pipeline
├── actors/                       # 3D models, textures, and behaviors for objects & enemies (e.g. Goombas, Bowser)
├── asm/                          # Low-level MIPS assembly files (e.g. bootloader, entry points)
├── assets/                       # Audio sequences, sound effects, and voice clips
├── bin/                          # Segment definitions, text scripts, and pre-compiled graphics binaries
├── data/                         # Behavior scripts, HUD textures, and camera spline coordinates
├── doxygen/                      # Documentation templates and configurations
├── enhancements/                 # Directory for optional community patches/mods
├── include/                      # C header files (.h) defining types, structs, and variables
├── levels/                       # Level layout scripts, object placements, and collision paths for each course
├── lib/                          # Standard Ultra64 SDK library source code (sound, thread manager, etc.)
├── rsp/                          # Reality Signal Processor (RSP) coprocessor assembly microcode
├── sound/                        # Sound sequence banks and audio configuration files
├── src/                          # Main gameplay C source code
│   ├── audio/                    # Sound player engine and audio handlers
│   ├── buffers/                  # Memory buffers and stack definitions
│   ├── engine/                   # Math utilities and collision detection math
│   ├── game/                     # Core gameplay logic (camera.c, mario.c, levels, interaction.c)
│   └── menu/                     # Intro screen and title screen menus
├── tools/                        # Compilers, asset converters, and asset compression utilities
│   ├── ido-static-recomp/        # Recompiled IDO C compiler for modern host systems
│   └── sm64tools/                # Custom graphics and texture compression tools
├── Makefile                      # Root build instructions configuration
├── assets.json                   # Asset configuration mapping baseline ROM offsets to source files
├── extract_assets.py             # Python script to extract files/textures from your baserom
└── undefined_syms.txt            # Symbols declared in assembly but not named in C yet
```

---

## 🛠️ Development Rules

To maintain codebase cleaniness and ensure build stability, please follow these rules during development:

1. **Build Verification (`COMPARE=0`):**
   * Because we are adding custom code, the compiled ROM's hash will no longer match the original vanilla N64 ROM.
   * **Rule:** Always compile using the `COMPARE=0` flag (e.g., `make VERSION=us COMPARE=0`). 

2. **No Repository ROM Uploads:**
   * **Rule:** Never check in, commit, or push baseline ROMs (`baserom.us.z64`, `super-mario-64.n64`, etc.) to public repositories due to copyright considerations.
   * Instead, use our GitHub Actions workflow which decodes the ROM from an encrypted repository secret (`BASEROM_US_BASE64`).

3. **Camera & Input Modification:**
   * Modify game engine behavior inside `src/game/` (e.g., `camera.c` for camera controls, `mario.c` for player physics).
   * Ensure that new controls do not clash with existing button layouts (e.g., we mapped centering to the **L Button** because it was unused during standard gameplay).

4. **Code Style:**
   * Run format checks before committing: `format.sh` or check files using `.clang-format` to align with the rest of the decompilation code structure.

---

## 🔨 How to Build Automatically on GitHub

The repository is pre-configured to build your ROM automatically using GitHub Actions.

### 1. Upload your US ROM to a File Host
Since the ROM is 8 MB and GitHub secrets are limited to 64 KB, you must upload your `baserom.us.z64` to a file host to get a direct download URL.
* **Option A (Catbox):** Go to [catbox.moe](https://catbox.moe/), upload your `baserom.us.z64` file, and copy the resulting short link (e.g. `https://files.catbox.moe/xxxxxx.z64`).
* **Option B (Dropbox):** Upload your `baserom.us.z64` to Dropbox, copy the share link, and change the end of the URL from `?dl=0` to `?dl=1` to make it a direct download link.

### 2. Add the URL Secret to GitHub
1. Go to your GitHub repository: `https://github.com/Canar8ue/SuperJarin64`
2. Go to **Settings > Secrets and variables > Actions**
3. Click **New repository secret**.
4. Configure the secret:
   * **Name:** `BASEROM_URL`
   * **Value:** Paste your direct download link.

### 3. Trigger Build and Download
* Every time you push changes to GitHub, the **Build SuperJarin64** workflow will automatically run.
* Once the run completes, go to the **Actions** tab on your repository, click the latest build run, and download the compiled `sm64-us-rom` zip file under the **Artifacts** section!

---

## 🛠️ Problem Log & Resolutions

This section documents key issues encountered during development and how they were solved:

### 1. Large Baserom Secret Size Limit Failure
* **Problem:** Storing the baseline ROM (`baserom.us.z64`) base64 string directly in GitHub Secrets crashed or failed because GitHub Secrets have a hard maximum limit of **64 KB** (the ROM is 8 MB).
* **Resolution:** Switched to storing a direct download link (`BASEROM_URL`) in the secrets pointing to a file sharing host (e.g. Catbox), and used `curl` in `.github/workflows/build.yml` to download it dynamically at compile time.

### 2. Warp Pipe Model ID Conflict
* **Problem:** Using `MODEL_WARP_PIPE` in the custom level `totwc` caused an undeclared compile error because warp pipes belong to the `common1` asset group, while `totwc` only loads the `common0` asset group.
* **Resolution:** Replaced the warp pipe teleporter with a physical cloud platform bridge featuring a horizontally moving checkerboard elevator. This keeps the asset footprint within `common0` and resolves the build conflict.

### 3. Solid Mezzanine Wall Blocking Warp Trigger
* **Problem:** Jumping at the middle window did not teleport the player. The wall behind the middle window is physically solid in the castle's 3D collision mesh, blocking Mario at `Z = -2724`, preventing him from touching the warp trigger placed at `Z = -2014` (which had a tiny default radius of `50` units).
* **Resolution:** Moved the warp trigger forward to `Z = -2680`, raised its height to `Y = 850`, and increased its detection radius to `200` units (`BPARAM1(20)`). This ensures that jumping against the middle window successfully triggers the warp without clipping through the wall.
