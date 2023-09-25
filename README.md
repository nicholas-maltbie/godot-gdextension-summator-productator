# Godot GDExtension Summator and Productator

Basic project to test importing multiple gdextension libraries.

```PowerShell
# Build godot-cpp
git -C godot-cpp submodule update --init
scons --directory godot-cpp

# Build summator project
scons --directory summator

# Build productator project
scons --directory productator

# Compile godot editor
scons --directory godot target=editor
```

## Windows build

```PowerShell
# Create godot export template
scons --directory godot platform=windows target=template_debug

# Compile godot-cpp
scons --directory godot-cpp platform=windows

# Build summator project
scons --directory summator platform=windows

# Build productator project
scons --directory productator platform=windows

# Build project with godot
```

## Javascript/Web build

```PowerShell
# Create godot export template
scons --directory godot platform=web dlink_enabled=yes target=template_debug

## Fixes for JavaScript/Web support
git -C godot-cpp apply --ignore-space-change --ignore-whitespace ../patches/fixed_javascript_build.patch
scons --directory godot-cpp platform=javascript

# Build summator project
scons --directory summator platform=javascript

# Build productator project
scons --directory productator platform=javascript
```
