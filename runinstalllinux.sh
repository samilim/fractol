#se mettre dans le dossier de la minilibx

sudo apt-get update && sudo apt-get install x11-apps
sudo apt-get install xorg libxext-dev zlib1g-dev

sudo apt install libxext-dev
sudo apt install libxrandr-dev
sudo apt install libx11-dev
sudo apt install libbsd-dev
sudo apt install libssl-dev

sudo cp man/man1/* /usr/local/man/man1/
sudo cp libmlx.a /usr/local/lib/
sudo cp mlx.h /usr/local/include/