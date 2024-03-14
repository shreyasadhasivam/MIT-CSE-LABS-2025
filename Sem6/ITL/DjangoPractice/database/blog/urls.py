from django.conf.urls import include
from django.urls import re_path
from blog.views import archive, create_blogpost

urlpatterns = [
    re_path(r'^$',archive,name='archive'),
    re_path(r'^create/',create_blogpost,name='create_blogpost'),
]