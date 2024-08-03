@echo off
setlocal enabledelayedexpansion

:: Define the base directories
set baseDirs=server app

:: Loop through each base directory
for %%d in (%baseDirs%) do (
    echo Processing directory: %%d
    :: Traverse each folder inside the base directory
    for /r %%f in (.) do (
        if exist %%f\NUL (
            echo Creating .gitkeep in %%f
            echo. > "%%f\.gitkeep"
        )
    )
)

echo All .gitkeep files have been created.
