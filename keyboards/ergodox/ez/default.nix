{ nixpkgs ? import <nixpkgs> {} }:
let
  inherit (nixpkgs) pkgs;
  packages = with pkgs; [ gcc gnumake unzip wget zip avrgcclibc
                          dfu-programmer dfu-util git
                          teensy-loader-cli
                        ];
in pkgs.stdenv.mkDerivation {
  name = "qmk_firmware";
  buildInputs =  packages;
}

