from django.db import models

# Create your models here.
class Member(models.Model):
    firstName = models.CharField(max_length = 255)
    lastName = models.CharField(max_length=255)