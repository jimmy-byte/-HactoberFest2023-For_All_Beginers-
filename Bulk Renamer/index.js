const fs = require('fs');
const replaceThis = "john";
const replaceWith = "babu";
const preview = true;
try {
    const data = fs.readdir("data", (err , data) => {
        for(let i = 0 ; i < data.length ; i++){
            const item = data[i];
            let newFile = "data/" + item.replaceAll(replaceThis , replaceWith);
            if(preview){
                fs.rename("data/" + item , newFile , () => {
                    console.log("Raname Success");
                });
            }
            else{
                if("data/" + item !== newFile){
                    console.log("data/" + item + " " + " will be remnamed to " + newFile);
                }
            }
            
        }
    });
} catch (err) {
    console.error(err);
}
