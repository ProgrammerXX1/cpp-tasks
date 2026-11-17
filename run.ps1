# Compile and run one C++ program (static link, sanitizers on).
# Usage:  .\run.ps1 name.cpp          (the .cpp is optional)
#         .\run.ps1 name.cpp in.txt   (feed in.txt to stdin)
param(
    [Parameter(Mandatory = $true)][string]$Src,
    [string]$Stdin
)

$ErrorActionPreference = 'Stop'
$g = 'C:\Users\User\mingw-tools\mingw64\bin\g++.exe'

if (-not $Src.EndsWith('.cpp')) { $Src = "$Src.cpp" }
if (-not (Test-Path $Src)) { Write-Error "No such file: $Src"; exit 1 }

$Src = (Resolve-Path $Src).Path
$exe = [System.IO.Path]::ChangeExtension($Src, '.exe')

& $g -std=c++17 -O2 -Wall -Wextra -g -D_GLIBCXX_ASSERTIONS -static $Src -o $exe
if ($LASTEXITCODE -ne 0) { Write-Error "Compilation failed"; exit $LASTEXITCODE }

chcp 65001 | Out-Null
Write-Host "--- run ---" -ForegroundColor Cyan
$sw = [System.Diagnostics.Stopwatch]::StartNew()
if ($Stdin) { Get-Content $Stdin | & $exe } else { & $exe }
$code = $LASTEXITCODE
$sw.Stop()
$ms = $sw.ElapsedMilliseconds
Write-Host "--- exit $code  ${ms} ms ---" -ForegroundColor Cyan
