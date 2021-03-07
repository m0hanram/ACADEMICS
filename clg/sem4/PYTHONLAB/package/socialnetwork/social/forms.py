from django import forms
from django.db import models
from django.forms import fields
from .models import Post, Comment


class PostForm(forms.ModelForm):
    body = forms.CharField(
        label='',
        widget=forms.Textarea(attrs={
            'rows': 3,
            'placeholder': 'Something interesting to share ?...'
        })
    )
    class Meta:
        model = Post
        fields = ['body']


class CommentForm(forms.ModelForm):
    comment = forms.CharField(
        label='',
        widget=forms.Textarea(attrs={
            'rows': 3,
            'placeholder': 'Add comment ...'
        })
    )
    class Meta:
        model = Comment
        fields = ['comment']