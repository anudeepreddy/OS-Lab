FROM gitpod/workspace-full:latest

RUN sudo apt-get install nodejs \
    && sudo apt-get install npm \
    && sudo npm install pm2 -g \
    && sudo npm install pm2 install xplorer -g
