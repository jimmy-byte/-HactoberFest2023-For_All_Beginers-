import React from 'react'
import Pic from "../images/signup_pic.jpg"
import "./styles/signup.css"

const Signup = () => {
  return (
  <>
  <div className="container2">
      <forrm method=" ">
        <div className="row">
            <div className="col-md-6">
                <img className='signupPic' src={Pic} alt="" />
            </div>
            <div className=" register col-md-6">
                <span>New User? <a>Login</a></span>
               
                <br/>
                <h3>Sign up</h3>
                <br/>
                <input type="text" placeholder='Your Name'/>
                <input type="text" placeholder='Your Email'/>
                <input type="text" placeholder='Mobile No.'/>
                <input type="text" placeholder='Your Profession'/>
                <input type="text" placeholder='Password'/>
                <input type="text" placeholder='Confirm Password'/>
                <br/>
                <br/>
               <button type='submit'>Register</button>
            </div>
        </div>
      </forrm>
  </div>
  </>
  )
}

export default Signup
