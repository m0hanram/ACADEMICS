import React from 'react'

const Book = (props) => {
  const {img, title, author} = props.book;
  const clickHandler = () => {
    alert('Hello World')
  }
  return (
    <article className="book">
      <img src={img} alt="" onClick={clickHandler} />
      <h1>{title}</h1>
      <h4>{author}</h4>
    </article>
  );
};

export default Book
