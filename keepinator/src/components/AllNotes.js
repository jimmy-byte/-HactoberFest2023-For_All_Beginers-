import React from "react";

const AllNotes = ({title, content, deleteItem, id}) => {

const deleteNote = () =>{
    deleteItem(id);
    console.log(id);
}

  return (
    <div>
      <div className="flex flex-col max-w-lg p-6 space-y-6 overflow-hidden rounded-lg shadow-md bg-gray-50 text-gray-800">
        <div>
          <h2 className="mb-1 text-xl font-semibold">
            {title}
          </h2>
          <p className="text-sm text-gray-600">
            {content}
          </p>
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
            <button
              aria-label="Bookmark this post"
              type="button"
              className="p-2"
            >
              <i className="fa-regular fa-pen-to-square font-bold w-4 h-4 text-l fill-current text-pink-600"></i>
            </button>

            <button
              aria-label="Bookmark this post"
              type="button"
              className="p-2"
              onClick={deleteNote}
            >
              <i className="fa-solid fa-trash font-bold w-4 h-4 text-l fill-current text-pink-600"></i>
            </button>
          </div>
          
        </div>
      </div>
    </div>
  );
};

export default AllNotes;
