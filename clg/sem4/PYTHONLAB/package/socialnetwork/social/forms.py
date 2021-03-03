from django import forms
from django.db import models
from django.forms import fields
from .models import Post


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