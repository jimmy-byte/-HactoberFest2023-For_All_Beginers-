function addNewWEField() {
  let newNode = document.createElement("textarea")
  newNode.classList.add("form-control")
  newNode.classList.add("WeField")
  newNode.classList.add("mt-2")
  newNode.setAttribute("rows", 2)
  newNode.setAttribute("placeholder", "Enter here")

  let weOb = document.getElementById("We")
  let weAddButtonob = document.getElementById("weAddButton")

  weOb.insertBefore(newNode, weAddButtonob)
}

function addNewAQField() {
  let newNode = document.createElement("textarea")
  newNode.classList.add("form-control")
  newNode.classList.add("AqField")
  newNode.classList.add("mt-2")
  newNode.setAttribute("rows", 2)
  newNode.setAttribute("placeholder", "Enter here")

  let aqOb = document.getElementById("Aq")
  let aqAddButtonob = document.getElementById("aqAddButton")

  aqOb.insertBefore(newNode, aqAddButtonob)
}

//generatecv
function generatecv() {
  let nameField = document.getElementById("nameField").value

  let nameT1 = document.getElementById("nameT1")

  nameT1.innerHTML = nameField

  document.getElementById("nameT2").innerHTML = nameField

  //contact
  document.getElementById("contactT").innerHTML =
    document.getElementById("contactField").value

  //address
  document.getElementById("addressT").innerHTML =
    document.getElementById("addressField").value

  //links
  document.getElementById("fbT").innerHTML =
    document.getElementById("fbField").value

  document.getElementById("instaT").innerHTML =
    document.getElementById("instaField").value

  document.getElementById("linT").innerHTML =
    document.getElementById("linField").value

  //objective
  document.getElementById("objT").innerHTML =
    document.getElementById("ObjField").value

  //we
  let wes = document.getElementsByClassName("WeField")

  let str = ""

  for (let e of wes) {
    str = str + `<li> ${e.value} </li>`
  }
  document.getElementById("weT").innerHTML = str

  //aq
  let aqs = document.getElementsByClassName("AqField")

  let str1 = ""

  for (let e of aqs) {
    str1 += `<li> ${e.value} </li>`
  }
  document.getElementById("aqT").innerHTML = str1

  //setting image
  let file = document.getElementById("imgField").files[0]

  console.log(file)

  let reader = new FileReader()

  reader.readAsDataURL(file)

  console.log(reader.result)

  //set the image to template

  reader.onloadend = function () {
    document.getElementById("imgT").SRC = reader.result
  }

  document.getElementById("cv-form").style.display = "none"
  document.getElementById("cv-template").style.display = "block"
}

//print cv
function printcv() {
  window.print()
}
