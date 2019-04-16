#!/bin/bash
if command -v python3 > /dev/null; then
  echo "Blackout server launched"
  python3 -m http.server 8888 --bind localhost
else
  echo "Blackout server launched"
  python -m SimpleHTTPServer 8888
fi
