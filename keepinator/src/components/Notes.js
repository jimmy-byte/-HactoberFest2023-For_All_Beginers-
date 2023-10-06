import React, { useState } from "react";

//  defined state for using note and using using multiple variables in one single usestate
const Notes = ({ passNote }) => {
  // to hide the expand state initially, setting it false to make it default
  const [expand, setExpand] = useState(false);

    const expandNote = () =>{
        setExpand(true);
    }

  const [note, setNote] = useState({
    title: "",
    content: "",
  });

  // setting inputEvent function to perform wrting action to text field
  const inputEvent = (event) => {
    // const value = event.target.value;
    // const name = event.target.value;
    // using object destructuring to use single line for declaring value and name variable
    const { name, value } = event.target;

    setNote((previousData) => {
      return {
        ...previousData,
        [name]: value,
      };
    });
  };

   

  const addEvent = (event) => {
    // passnote (note) will send the note data to the main component to use the passed information for making list of notes
    passNote(note);

    // to make title and content empty after adding to list of notes
    setNote({
      title: "",
      content: "",
    });

    setExpand(false);
  };
  return (
    <div >
      <div className="flex flex-col max-w-lg p-4 space-y-2 overflow-hidden rounded-lg shadow-md bg-gray-50 text-gray-800"
      
      >
        <div>
          <h2 className="mb-1 text-xl font-semibold">New Note</h2>

           {/* if expand is true than it will show only */}
          {expand ? (
            <>
            <input
              className="text-sm text-gray-600 w-full my-4 p-2 rounded-lg"
              type="text"
              value={note.title}
              onChange={inputEvent}
              name="title"
              placeholder="Title"
            ></input>
          </> ): null}
          <textarea
            id="bio"
            name="content"
            value={note.content}
            onChange={inputEvent}
            onClick={expandNote}
            placeholder="write your note "
            className="w-96 rounded-md focus:ring focus:ring-opacity-75 focus:ring-pink-600 border-gray-300 text-gray-900 h-full"
            spellCheck="true"
          ></textarea> 
        </div>
        <div className="flex flex-wrap justify-between">
          <div className="space-x-2">
            <button
              aria-label="Share this post"
              type="button"
              className="p-2 text-center"
            >
              <i className="fa-solid fa-share-nodes w-4 h-4 text-l fill-current text-pink-600"></i>
            </button>
          </div>
          <div className="flex space-x-2 text-sm text-gray-600">
            <button
              type="button"
              className="flex items-center p-1 space-x-1.5"
              onClick={addEvent}
            >
              <i className="fa-regular fa-plus w-4 h-4 text-xl font-extrabold fill-current text-pink-600"></i>
            </button>
          </div>
          
        </div>
        
      </div>
    </div>
  );
};

export default Notes;
