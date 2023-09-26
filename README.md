# Godot GDExtension Summator and Productator

Basic project to test importing multiple gdextension libraries.

```PowerShell
# Build godot-cpp for current platform
git -C godot-cpp submodule update --init
scons --directory godot-cpp

# Build summator project for current platform
scons --directory summator

# Build productator project for current platform
scons --directory productator

# Compile godot editor
scons --directory godot target=editor

# Optional, open godot project
$godot = "godot\bin\godot.windows.editor.x86_64.exe"
&$godot -e --path game
```

## Windows build

```PowerShell
# Create godot export template
scons --directory godot platform=windows target=template_debug
mkdir -p game\templates
mv .\godot\bin\godot.windows.template_debug.x86_64.* game\templates\

# Compile godot-cpp
scons --directory godot-cpp platform=windows

# Build summator project
scons --directory summator platform=windows

# Build productator project
scons --directory productator platform=windows

# Build project with godot
$godot = "godot\bin\godot.windows.editor.x86_64.exe"

# Open project to generate .godot files for gdextensions
&$godot -v -e --headless --path game --quit

# Build for windows platform.
mkdir -p game/builds/windows
&$godot -v --headless --path game --export-debug "Windows Desktop"
```

## Javascript/Web build

```PowerShell
# Optional, apply patch to allow building on windows.
git -C godot apply --ignore-space-change --ignore-whitespace ..\patches\fixed_godot_javascript_subprocess.patch

# Create godot export template
scons --directory godot platform=web dlink_enabled=yes target=template_debug
mkdir -p game\templates
mv .\godot\bin\godot.web.template_debug.wasm32.dlink.zip game\templates\

## Fixes for JavaScript/Web support
git -C godot-cpp apply --ignore-space-change --ignore-whitespace ../patches/fixed_javascript_build.patch
scons --directory godot-cpp platform=javascript

# Build summator project
scons --directory summator platform=javascript

# Build productator project
scons --directory productator platform=javascript

# Build project with godot
$godot = "godot\bin\godot.windows.editor.x86_64.exe"

# Open project to generate .godot files for gdextensions
&$godot -v -e --headless --path game --quit

# Build for web platform.
mkdir -p game/builds/web
&$godot -v --headless --path game --export-debug "Web"

# Optional: host site via npx
npx local-web-server `
>>   --cors.embedder-policy "require-corp" `
>>   --cors.opener-policy "same-origin" `
>>   --directory game\builds\web
```
