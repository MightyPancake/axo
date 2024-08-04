{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = [
    pkgs.nodejs
  ];

  shellHook = ''
    # Install docsify-cli if not already installed
    if ! command -v docsify &> /dev/null; then
      npm install -g docsify-cli
    fi
  '';
}