const hourEl = document.querySelector(".hours");
const minel = document.querySelector(".mins");
const secEl = document.querySelector(".secs");


function updateClock(){

    let h = new Date().getHours();
    let m = new Date().getMinutes();
    let s = new Date().getSeconds();

    h = h<10 ? "0" + h : h;
    m = m<10 ? "0" + m : m;
    s = s<10 ? "0" + s : s;

    hourEl.textContent = h;
    minel.textContent = m;
    secEl.textContent = s;
    console.log(1)
    setTimeout(updateClock,1000)
}

updateClock();

