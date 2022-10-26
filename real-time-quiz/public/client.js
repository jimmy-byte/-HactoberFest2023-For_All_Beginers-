// const radioBtns = document.getElementsByName('1');
// console.log(radioBtns.length);
// for (let i = 0; i < radioBtns.length; i++) {
//   radioBtns[i].disabled = true;
// }

const socket = io();
// console.log(socket);
socket.emit('client', { socketID: socket.id });

let ques;
let opt;
function handleChange1(e) {
  // console.log(e.id);
  const option = e.id.split('');
  ques = parseInt(option[0]);
  opt = parseInt(option[1]);
  const radioBtns = document.getElementsByName(`${ques}`);
  for (let i = 0; i < radioBtns.length; i++) {
    radioBtns[i].disabled = true;
  }
  socket.emit('answer', { ques: ques, opt: opt });

  // console.log('ques= ', ques, ' opt=', opt);
}
function handleChange2(e) {
  const option = e.id.split('');
  ques = parseInt(option[0]);
  opt = parseInt(option[1]);
  const radioBtns = document.getElementsByName(`${ques}`);
  for (let i = 0; i < radioBtns.length; i++) {
    radioBtns[i].disabled = true;
  }
  socket.emit('answer', { ques: ques, opt: opt });
  // console.log('ques= ', ques, ' opt=', opt);
}
function handleChange3(e) {
  // console.log(e);
  const option = e.id.split('');
  ques = parseInt(option[0]);
  opt = parseInt(option[1]);
  const radioBtns = document.getElementsByName(`${ques}`);
  for (let i = 0; i < radioBtns.length; i++) {
    radioBtns[i].disabled = true;
  }
  socket.emit('answer', { ques: ques, opt: opt });
  // console.log('ques= ', ques, ' opt=', opt);
}

function handleChange4(e) {
  // console.log(e);
  const option = e.id.split('');
  ques = parseInt(option[0]);
  opt = parseInt(option[1]);
  const radioBtns = document.getElementsByName(`${ques}`);
  for (let i = 0; i < radioBtns.length; i++) {
    radioBtns[i].disabled = true;
  }
  socket.emit('answer', { ques: ques, opt: opt });
  // console.log('ques= ', ques, ' opt=', opt);
}
function selectedOPtion(question, option) {
  switch (option) {
    case 1:
      return question.option1.vote;
    case 2:
      return question.option2.vote;
    case 3:
      return question.option3.vote;
    case 4:
      return question.option4.vote;
    default:
      return 0;
  }
}

function percentage(vote, totalVotes) {
  const val = totalVotes === 0 ? totalVotes : (vote * 100) / totalVotes;
  return val.toFixed(0);
}

socket.on('questions', (data) => {
  // console.log(data);
  const { question, option } = data;
  // const vote = selectedOPtion(question, option);
  // const totalVotes = question.totalVote;
  // const percentage = (vote * 100) / totalVotes;
  $(`#q${question.id}${1}`).html(
    `${percentage(question.option1.vote, question.totalVote)}%`
  );
  $(`#q${question.id}${2}`).html(
    `${percentage(question.option2.vote, question.totalVote)}%`
  );
  $(`#q${question.id}${3}`).html(
    `${percentage(question.option3.vote, question.totalVote)}%`
  );
  $(`#q${question.id}${4}`).html(
    `${percentage(question.option4.vote, question.totalVote)}%`
  );
});
