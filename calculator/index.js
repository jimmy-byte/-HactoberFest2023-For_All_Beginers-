class Calculator{
    constructor(previousOperandTextElement,currentOperandTextElement)
    {
        this.previousOperandTextElement = previousOperandTextElement
        this.currentOperandTextElement = currentOperandTextElement
        this.clear()
    }
    clear()
    {
        this.currentOperand = ''
        this.previousOperand = ''
        this.operation = undefined      
    }
    appendNumber(number)
    {
        if(number === '.' && this.currentOperand.includes('.')) return  
        this.currentOperand = this.currentOperand.toString() + number.toString();
    }
    delete()
    {
        this.currentOperand = this.currentOperand.toString().slice(0 ,-1);
    }
    chooseOperation(operation)
    {
        if(this.currentOperand === '') return
        if(this.previousOperand != '')
        {
            this.compute();
        }
        this.operation = operation;
        this.previousOperand = this.currentOperand;
        this.currentOperand = '';  

    }
    compute(){
        let computation
        const prev = parseFloat(this.previousOperand);
        const current = parseFloat(this.currentOperand);
        if(isNaN(prev)  || isNaN(current)) return ;
        switch (this.operation){
            case '+':
            computation = prev + current;
            break;
            case '-':
            computation = prev - current;
            break;
            case '*':
            computation = prev * current;
            break;
            case '÷':
            computation = prev / current;
            break;
            default : 
            return 
            
        }
        // console.log("i m here");
        this.currentOperand = computation;
        this.operation = undefined;
        this.previousOperand = '';

        
    }
    updateDisplay()
    {
        this.currentOperandTextElement.innerText = this.currentOperand;
        // this.previousOperandTextElement.innerText = this.previousOperand;
        if(this.operation != null)
        {
            this.previousOperandTextElement.innerText = `${this.previousOperand} ${this.operation}`
        }
        else {
            this.previousOperandTextElement.innerText = '';
        }

    }
}
const number = document.querySelectorAll('[data-number]');
// console.log(number);
const previousOperandTextElement = document.querySelector('[data-previous-operand]');
const currentOperandTextElement = document.querySelector('[data-current-operand]');
const del = document.querySelector('[data-delete]');
console.log(del);
const ac = document.querySelector('[data-all-clear]');
const equals = document.querySelector('[data-equals]');
const operator = document.querySelectorAll('[data-operator]');

const calculator = new Calculator(previousOperandTextElement,currentOperandTextElement);

number.forEach(button=>{
    button.addEventListener('click',()=>{
        calculator.appendNumber(button.innerText);
        calculator.updateDisplay();

    });
});
operator.forEach(button=>{
    button.addEventListener('click',()=>
    {
        calculator.chooseOperation(button.innerText);
        calculator.updateDisplay();
    })
})
ac.addEventListener('click', ()=>{
    calculator.clear();
    calculator.updateDisplay();
});
equals.addEventListener('click', button =>{
    calculator.compute();
    calculator.updateDisplay();

})
del.addEventListener('click', button =>{
    calculator.delete();
    calculator.updateDisplay();

})
