{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    pkgs.python3
    pkgs.python3
    pkgs.emscripten
    pkgs.bison
    pkgs.flex
    pkgs.valgrind
    pkgs.fish
  ];

  shellHook = ''
    exec fish
  '';
}
