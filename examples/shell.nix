{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = [
    pkgs.miniaudio
    pkgs.raylib
    pkgs.alsaLib
    pkgs.pulseaudio
    pkgs.jack2
  ];

  shellHook = ''
    export MINIAUDIO_BACKEND=pulseaudio
  '';
}