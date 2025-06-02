FROM node:10


ARG NODE_PORT


RUN echo "Argument port is : $NODE_PORT"


WORKDIR /usr/src/app


COPY package.json /usr/src/app/package.json



RUN npm install

COPY . /usr/src/app


EXPOSE ${NODE_PORT}

CMD npm run dev


