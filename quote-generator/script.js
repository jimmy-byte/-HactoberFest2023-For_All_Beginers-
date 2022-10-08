const quoteContainer = document.getElementById('quote-container');
const quoteText = document.getElementById('quote');
const authorText = document.getElementById('author');
const twitterBtn = document.getElementById('twitter'); 
const newQuoteBtn = document.getElementById('new-quote'); 
const loader = document.getElementById('loader');

let apiQuotes=[];

//Show Loading
function loading(){
    loader.hidden = false;
    quoteContainer.hidden = true;
}

//complete loading
function complete(){
    loader.hidden = true;
    quoteContainer.hidden = false;
}


//show new Quote
function newQuote(){
    loading()
    const quote = apiQuotes[Math.floor(Math.random() * apiQuotes.length)];
    console.log(quote)

    if(!quote.author){
        authorText.textContent = 'Anonymous';
    }else{
        authorText.textContent = quote.author;
    }

    quoteText.textContent = quote.text;

    if(quote.text.length > 100){
        quoteText.classList.add('long-quote')
    }else{
        quoteText.classList.remove('long-quote')
    }

    complete();
}

// Get Quotes from API
async function getQuotes(){
    loading();
    const apiUrl='https://type.fit/api/quotes';
    try{
        const response = await fetch(apiUrl);
        apiQuotes = await response.json();
        newQuote();
        complete();
    } catch(error) { 
        //error handling
    }
}

//Tweet quote

function tweetQuote(){
    const twitterUrl = `https://twitter.com/intent/tweet?text=${quoteText.textContent} - ${authorText.textContent}`;
    window.open(twitterUrl, '_blank');
}

//tEvent Listeners

newQuoteBtn.addEventListener('click', newQuote);
twitterBtn.addEventListener('click', tweetQuote);

//on Load
getQuotes();
