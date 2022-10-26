const express = require('express');
const socketIO = require('socket.io');
const http = require('http');

const PORT = process.env.PORT || 4321;
const app = express();

app.use('/', express.static(__dirname + '/public'));

const questions = [
  {
    question: 'Which of the following is the correct name of React.js?',
    id: 1,
    option1: {
      desc: 'React',
      vote: 0,
    },
    option2: {
      desc: 'React.js',
      vote: 0,
    },
    option3: {
      desc: 'ReactJS',
      vote: 0,
    },
    option4: {
      desc: 'All of the above',
      vote: 0,
    },
    disabled: false,
    totalVote: 0,
  },
  {
    question: 'Which of the following are the advantages of React.js?',
    id: 2,
    option1: {
      desc: `React.js can increase the application's performance with Virtual DOM.`,
      vote: 0,
    },
    option2: {
      desc: 'React.js is easy to integrate with other frameworks such as Angular, BackboneJS since it is only a view library.',
      vote: 0,
    },
    option3: {
      desc: 'React.js can render both on client and server side.',
      vote: 0,
    },
    option4: {
      desc: 'All of the above',
      vote: 0,
    },
    disabled: false,
    totalVote: 0,
  },
  {
    question: 'Which of the following is not a disadvantage of React.js?',
    id: 3,
    option1: {
      desc: `React.js has only a view layer. We have put your code for Ajax requests, events and so on.`,
      vote: 0,
    },
    option2: {
      desc: 'The library of React.js is pretty large.',
      vote: 0,
    },
    option3: {
      desc: 'The JSX in React.js makes code easy to read and write.',
      vote: 0,
    },
    option4: {
      desc: 'The learning curve can be steep in React.js.',
      vote: 0,
    },
    disabled: false,
    totalVote: 0,
  },
  {
    question:
      'Which of the following option is correct in the case of the Babel?',
    id: 4,
    option1: {
      desc: `Babel is a Compiler.`,
      vote: 0,
    },
    option2: {
      desc: 'Babel is a Transpilar.',
      vote: 0,
    },
    option3: {
      desc: 'None of the above.',
      vote: 0,
    },
    option4: {
      desc: 'Both A and B are correct.',
      vote: 0,
    },
    disabled: false,
    totalVote: 0,
  },
];

// const server = http.Server(app);
const server = http.createServer(app);
const io = socketIO(server);

function increaseVote(quesNo, optionNo) {
  switch (optionNo) {
    case 1:
      questions[quesNo - 1].option1.vote =
        questions[quesNo - 1].option1.vote + 1;
      questions[quesNo - 1].totalVote++;
      questions[quesNo - 1].disabled = true;
      break;
    case 2:
      questions[quesNo - 1].option2.vote =
        questions[quesNo - 1].option2.vote + 1;
      questions[quesNo - 1].totalVote++;
      questions[quesNo - 1].disabled = true;
      break;
    case 3:
      questions[quesNo - 1].option3.vote =
        questions[quesNo - 1].option3.vote + 1;
      questions[quesNo - 1].totalVote++;
      questions[quesNo - 1].disabled = true;
      break;
    case 4:
      questions[quesNo - 1].option4.vote =
        questions[quesNo - 1].option4.vote + 1;
      questions[quesNo - 1].totalVote++;
      questions[quesNo - 1].disabled = true;
      break;
    default:
      break;
  }
}

app.get('/questions', (req, res) => {
  res.send({ questions: questions });
});

let users = [];
io.on('connection', (socket) => {
  console.log('connected', socket.id);
  socket.on('client', (data) => {
    console.log('client = ', data);
  });
  socket.on('answer', (data) => {
    console.log(data);
    increaseVote(data.ques, data.opt);
    io.sockets.emit('questions', {
      question: questions[data.ques - 1],
      option: data.opt,
    });
  });
  socket.on('disconnect', () => {
    users = users.filter((id) => id !== socket.id);
    console.log('disconncted', users);
  });
});

server.listen(PORT, () => {
  console.log(`server started on http://localhost:${PORT}`);
});
