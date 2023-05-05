const Folder = "./";
const fs = require('fs');

const MEMTRACE = true;

fs.readdir(Folder, (err, files) => {
  files.forEach(file => {
    let filename = file.split(".")[0];
    let ext = file.split(".")[1];
    if(ext == "cpp") {
        console.log(`g++ -Wall -Werror -pedantic -std=c++17 -g ${MEMTRACE  ? "-DMEMTRACE" : ""} -c ${filename}.cpp -o ${filename}.o`)
    }
  });
});
