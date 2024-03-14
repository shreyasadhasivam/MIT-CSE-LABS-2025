"""
URL configuration for database project.

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/4.2/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path,re_path
from django.conf.urls import include

from django.contrib import admin
admin.autodiscover()
urlpatterns = [
    path('admin/', admin.site.urls),
    #re_path(r'^$', blog.views.archive, name='archive'), 
    #re_path(r'^blog/', include('blog.MyBlog.rls')), 
 # Uncomment the admin/doc line below to enable admin documentation: 
    re_path(r'^admin/doc/', include('django.contrib.admindocs.urls')),
    (r'^$', 'django.views.generic.simple.redirect_to', 
    {'url': '/blog/'}), 
    re_path(r'^blog/', include('blog.urls')), 
    re_path(r'^admin/', include(admin.site.urls)), 
]
