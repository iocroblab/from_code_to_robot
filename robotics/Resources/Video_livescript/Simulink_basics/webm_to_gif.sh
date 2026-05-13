#!/usr/bin/env bash
set -euo pipefail

FPS=15
WIDTH=640

for input in *.webm; do
  [ -e "$input" ] || continue

  base="${input%.*}"
  palette="${base}_palette.png"
  output="${base}.gif"

  echo "Converting: $input -> $output"

  ffmpeg -y -i "$input" \
    -vf "fps=${FPS},scale=${WIDTH}:-1:flags=lanczos,palettegen" \
    "$palette"

  ffmpeg -y -i "$input" -i "$palette" \
    -lavfi "fps=${FPS},scale=${WIDTH}:-1:flags=lanczos[x];[x][1:v]paletteuse" \
    "$output"

  rm "$palette"
done 
