import React from 'react';
import ReactDOM from 'react-dom';

const Element = <h1>HELLO world</h1>;
ReactDOM.render(Element , document.getElementById('root'));

if (module.hot) {
    module.hot.accept();
  }