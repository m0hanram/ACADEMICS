import React from 'react'
import ReactDom from 'react-dom'

import './index.css'
import {books} from './books'
import Book from './Book'

function BookList(){
  return (
    <section className="booklist">
      {books.map((book) => {
        return (
          <Book book={book}></Book>
        )
      })}
    </section>
  )
}


if (module.hot) {
    module.hot.accept();
};

ReactDom.render(<BookList/>, document.getElementById('root'));

