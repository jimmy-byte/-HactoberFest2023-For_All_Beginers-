$(function () {
  $.get('/questions', async (data) => {
    const questions = await data;
    await loadQuestions(questions.questions);
  });
});

function percentage(vote, totalVotes) {
  const val = totalVotes === 0 ? totalVotes : (vote * 100) / totalVotes;
  return val.toFixed(0);
}

function loadQuestions(questions) {
  let temp = ``;
  for (let question of questions) {
    temp += `
      <li>
      <div class='question'>
        <div class="question-desc">
          <div>${question.question}</div>
        </div>
        <div class='question-options'>
          <div class='label-input'>
            <input
              id=${question.id}1
              type='radio'
              name=${question.id}
              onchange="handleChange1(this)"
              .disabled=${false}
            />
            <div class='label'>
              <div class='option'>${question.option1.desc}</div>
              <div id=q${question.id}1 class='progress-text'>${percentage(
      question.option1.vote,
      question.totalVote
    )}%</div>
            </div>
          </div>
      
          <div  class='label-input'>
            <input
              id=${question.id}2
              type='radio'
              name=${question.id}
              onchange="handleChange2(this)"
            />
             <div class='label'>
              <div class='option'>${question.option2.desc}</div>
              <div id=q${question.id}2  class='progress-text'>${percentage(
      question.option2.vote,
      question.totalVote
    )}%</div>
            </div>
          </div>
      
          <div class='label-input'>
            <input
              id=${question.id}3
              type='radio'
              name=${question.id}
              onchange="handleChange3(this)"
            />
            <div class='label'>
              <div class='option'>${question.option3.desc}</div>
              <div id=q${question.id}3  class='progress-text'>${percentage(
      question.option3.vote,
      question.totalVote
    )}%</div>
            </div>
          </div>
      
          <div class='label-input'>
            <input
              id=${question.id}4
              type='radio'
              name=${question.id}
              onchange="handleChange4(this)"
            />
            <div class='label'>
              <div class='option'>${question.option4.desc}</div>
              <div id=q${question.id}4  class='progress-text'>${percentage(
      question.option4.vote,
      question.totalVote
    )}%</div>
            </div>
          </div>
        </div>
      </div>
      </li>
      `;
  }
  $('#question-list').append(temp);
}

// fetch('/questions')
//   .then((res) => res.json())
//   .then((res) => console.log(res))
