## Copyright (C) 2021 mohan
##
## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <https://www.gnu.org/licenses/>.

## -*- texinfo -*-
## @deftypefn {} {@var{retval} =} eval (@var{input1}, @var{input2})
##
## @seealso{}
## @end deftypefn

## Author: mohan <mohan@LAPTOP-HTV57VOH>
## Created: 2021-02-09

function y = eval (x)
  y = 1:length(x);
  for i = 1:length(x),
    y(i) = ((x(i).^4)*sqrt((3*x(i))+5))/(((x(i).^2)+1)^2);
  endfor
endfunction