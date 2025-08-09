FROM nginx:latest

COPY nginx.conf /etc/nginx/nginx.conf
COPY curel.conf /etc/nginx/sites-available/

RUN mkdir -p /etc/nginx/sites-enabled/\
    && ln -s /etc/nginx/sites-available/curel.conf /etc/nginx/sites-enabled/

CMD ["nginx", "-g", "daemon off;"]