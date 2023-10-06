import React, { useState } from "react";
import AllNotes from "../components/AllNotes";
import Header from "../components/Header";
import Notes from "../components/Notes";

const Main = () => {
  const [addItem, setAddItem] = useState([]);
  const addNote = (note) => {
    setAddItem((previousData) => {
      return [...previousData, note];
    });
  };

  const onDelete = (id) => {
    // now for deleting it have to match the id of the note
    setAddItem((previousData) => 

    // it will filter and show all the notes having id not equal to index
      previousData.filter((currentData, index) => {
        return index !== id;
      })
    );
  };

  return (
    <div>
      <Header />
      <div className="flex m-10 mt-20 justify-center">
        <Notes passNote={addNote} />
      </div>
      <div className="flex m-10 flex-wrap flex-row gap-6 items-center justify-center">
        {addItem.map((val, index) => {
          return (
            <AllNotes
              key={index}
              id={index}
              title={val.title}
              content={val.content}
              deleteItem={onDelete}
            />
          );
        })}
      </div>
    </div>
  );
};

export default Main;
